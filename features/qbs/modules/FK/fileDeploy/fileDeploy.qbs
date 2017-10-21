import qbs
import qbs.File
import qbs.FileInfo
import qbs.TextFile
import qbs.Process

Module{

    property path destinationRoot
    property path deploySourceRoot: product.sourceDirectory

    Rule{
        inputs: ["fk.deployable", "fk.content"]
        outputArtifacts: {
            var location = input.fileTags.contains("fk.content") ? input.FK.content.location : "/."
            var sourceRoot =  input.fileTags.contains("fk.content") ? input.FK.content.sourceRoot  : input.FK.fileDeploy.deploySourceRoot
            var targetPath = "/" + (sourceRoot === undefined ? input.fileName : FileInfo.relativePath(sourceRoot, input.filePath))
            return [{
                filePath: input.FK.fileDeploy.destinationRoot + location + targetPath,
                fileTags: input.fileTags.contains("application") ? ["fk.deployedFile", "fk.deployedApplication"] : ["fk.deployedFile"]
            }]
        }
        outputFileTags: ["fk.deployedFile", "fk.deployedApplication"]
        prepare: {
            if(input.FK.fileDeploy.destinationRoot === undefined){
                throw "FK.fileDeploy.destinationRoot is undefined for " + input.filePath
            }
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

}
