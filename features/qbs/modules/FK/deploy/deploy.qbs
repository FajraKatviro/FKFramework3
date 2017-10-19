import qbs
import qbs.File
import qbs.FileInfo
import qbs.TextFile
import qbs.Process

Module{

    property path root: "."

    Rule{
        inputs: ["deployable"]
        outputArtifacts:{
            if(input.fileTags.contains("application")){
                return [{
                    filePath: FileInfo.path(input.FK.deploy.root + "/") + "/" + input.fileName,
                    fileTags: ["predeployedPackage"]
                }]
            } else {
                return [{
                    filePath: FileInfo.path(input.FK.deploy.root + "/" + FileInfo.path(FileInfo.relativePath(product.sourceDirectory, input.filePath)) + "/") + "/" + input.fileName,
                    fileTags: ["deployedPackage"]
                }]
            }
        }
        outputFileTags: [
            "deployedPackage",
            "predeployedPackage"
        ]
        prepare: {
            var cmd = new JavaScriptCommand()
            cmd.description = input.filePath + " -> " + output.filePath
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
        inputs: ["predeployedPackage"]
        condition: qbs.targetOS.contains("linux")
        Artifact{
            filePath: input.filePath + ".sh"
            fileTags: ["deployedPackage"]
        }
        prepare: {
            var cmd = new JavaScriptCommand()
            cmd.description = "deploy linux executable..."
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
