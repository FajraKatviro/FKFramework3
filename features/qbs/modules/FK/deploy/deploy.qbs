import qbs
import qbs.File
import qbs.FileInfo
import qbs.TextFile
import qbs.Process

Module{

    property path destinationRoot
    property path deploySourceRoot: product.sourceDirectory

    validate: {
        if (destinationRoot === undefined){
            throw "FK.deploy.destinationRoot is undefined"
        }
    }

    Group{
        fileTagsFilter: "application"
        fileTags: "fk.deployable"
        overrideTags: false
        FK.deploy.deploySourceRoot: undefined
    }

    Rule{
        inputs: ["fk.deployable", "fk.content"]
        outputArtifacts: {
            var location = input.fileTags.contains("fk.content") ? input.FK.content.location : "/."
            var sourceRoot =  input.fileTags.contains("fk.content") ? input.FK.content.sourceRoot  : input.FK.deploy.deploySourceRoot
            var targetPath = "/" + (sourceRoot === undefined ? input.fileName : FileInfo.relativePath(sourceRoot, input.filePath))
            return [{
                filePath: input.FK.deploy.destinationRoot + location + targetPath,
                fileTags: input.fileTags.contains("application") ? ["fk.deployedFile", "fk.deployedApplication"] : ["fk.deployedFile"]
            }]
        }
        outputFileTags: ["fk.deployedFile", "fk.deployedApplication"]
        prepare: {
            var cmd = new JavaScriptCommand()
            cmd.description = "Copy deployable file " + input.filePath + " to " + output.filePath
            cmd.sourceCode = function() {
                if(File.exists(output.filePath))
                    File.remove(output.filePath)
                File.copy(input.filePath, output.filePath)
            }
            return [cmd]
        }
        alwaysRun: true
    }

    Rule{
        inputs: ["fk.deployedApplication"]
        condition: qbs.targetOS.contains("linux")
        Artifact{
            filePath: input.filePath + ".sh"
            fileTags: ["fk.deployedFile"]
        }
        prepare: {
            var cmd = new JavaScriptCommand()
            cmd.description = "Deploy executable (linux) " + input.filePath
            cmd.sourceCode = function() {
                if(File.exists(output.filePath))
                    File.remove(output.filePath)
                var file = TextFile(output.filePath, TextFile.WriteOnly)
                file.write("./" + input.fileName)
                Process().exec("chmod", ["+x", output.filePath])
            }
            return [cmd]
        }
        alwaysRun: true
    }
}
