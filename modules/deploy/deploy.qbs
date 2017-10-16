import qbs
import qbs.File
import qbs.FileInfo
import qbs.TextFile
import qbs.Process
import "../../paths/fkframework.js" as FKPaths

Module{

    property string root: ""

    readonly property string frameworkPath: FKPaths.frameworkPath(qbs.hostOS)

    Rule{
        inputs: ["deployable"]
        Artifact{
            filePath: FileInfo.path(product.deploy.frameworkPath + "/" + input.deploy.root + "/" + FileInfo.path(FileInfo.relativePath(product.sourceDirectory, input.filePath)) + "/") + "/" + input.fileName
            fileTags: ["deployedPackage"]
        }
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
        inputs: ["application"]
        Artifact{
            filePath: FileInfo.path(product.deploy.frameworkPath + "/" + input.deploy.root + "/") + "/" + input.fileName
            fileTags: ["predeployedApp"]
        }
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
        inputs: ["predeployedApp"]
        condition: qbs.targetOS.contains("linux")
        Artifact{
            filePath: input.filePath + ".sh"
            fileTags: ["deployedApp"]
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
