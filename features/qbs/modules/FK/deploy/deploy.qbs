import qbs
import qbs.File
import qbs.FileInfo
import qbs.TextFile
import qbs.Process

Module{

    property path destinationRoot

    Depends{ name: "FK.fileDeploy" }

    Group{
        fileTagsFilter: "application"
        fileTags: "fk.deployable"
        overrideTags: false
        FK.fileDeploy.deploySourceRoot: undefined
        FK.fileDeploy.destinationRoot: FK.deploy.destinationRoot
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
