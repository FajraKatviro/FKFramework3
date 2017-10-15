import qbs
import qbs.File
import qbs.FileInfo
import "../../paths/fkframework.js" as FKPaths

Module{

    property string root: ""

    readonly property string frameworkPath: FKPaths.frameworkPath(qbs.hostOS)

    Rule{
        inputs: ["deployable"]
        Artifact{
            filePath: FileInfo.path(product.deploy.frameworkPath + "/" + FileInfo.path(FileInfo.relativePath(product.sourceDirectory, input.filePath)) + "/" + input.deploy.root  + "/") + "/" + input.fileName
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
}
