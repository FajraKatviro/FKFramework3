import qbs
import qbs.File
import qbs.FileInfo
import "../../../scripts/fkframeworkpath.js" as FKPaths

Module{

    property path buildFolder: product.buildDirectory + "/imageset"
    property path location: "/constAppData"
    property path sourceRoot

    Depends{ name: "Qt.core" }
    readonly property path rccPath: Qt.core.binPath + "/rcc"
    property path utilsFolder: FKPaths.frameworkPath(qbs.hostOS) + "/utils"

    Depends{ name: "FK.content" }

    validate: {
        if (FK.imageset.sourceRoot === undefined){
            throw "Unable create imageset. Set FK.imageset.sourceRoot to art location"
        }
    }

    Rule{
        requiresInputs: false
        alwaysRun: true
        outputArtifacts: {
            var File = require("qbs.File")
            var out = []
            var dirs = File.directoryEntries(FK.imageset.sourceRoot, File.NoDotAndDotDot | File.Dirs)
            for (var i = 0; i < dirs.length; ++i) {
                out.push({
                    filePath: FK.imageset.sourceRoot + "/" + dirs[i] + "/package.json",
                    fileTags: "fk.imagesetSource"
                })
            }
            return out
        }
        outputFileTags: ["fk.imagesetSource"]
        prepare: {
            var cmd = new Command(FK.imageset.utilsFolder + "/PackageManager" [FK.imageset.sourceRoot, "--dir"])
            cmd.description = "Process imageset source folder: " + FK.imageset.sourceRoot
            cmd.highlight = "filegen"
            return [cmd]
        }
    }

    Rule{
        inputs: "fk.imagesetSource"
        multiplex: true
        Artifact{
            filePath: FK.imageset.buildFolder + "/resourceList.txt"
            fileTags: "fk.imagesetResourceList"
        }
        prepare: {
            var cmd = new Command(FK.imageset.utilsFolder + "/PackageGenerator" [FK.imageset.sourceRoot, FK.imageset.buildFolder, "--dir", "--resources", output.filePath])
            cmd.silent = true
            return [cmd]
        }
    }

    Rule{
        inputs: ["fk.imagesetResourceList"]
        outputArtifacts: {
            var resourceList = TextFile(input.filePath)
            var out = []
            while (!resourceList.atEof()) {
                var resourcePath = resourceList.readLine()
                out.push({
                    filePath: resourcePath,
                    fileTags: "fk.content",
                    FK.content.location: FK.imageset.location,
                    FK.content.sourceRoot: FK.imageset.buildFolder + "/bin"
                })
            }
            return out
        }
        outputFileTags: ["fk.content"]

        prepare: {
            var cmd = Command(FK.imageset.utilsFolder + "/PackageGenerator", [FK.imageset.sourceRoot, FK.imageset.buildFolder, "--clean", "--add", "--qrc", "--rcc", "--dir", "--qtbin", FK.imageset.rccPath])
            cmd.description = "Generate resources for " + FK.imageset.sourceRoot
            cmd.highlight = "filegen"
            return [cmd]
        }
    }

}

