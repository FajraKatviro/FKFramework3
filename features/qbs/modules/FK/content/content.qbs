import qbs
import qbs.FileInfo

Module{

    property path buildFolder: product.buildDirectory + "/builtResources"
    property path location: "/constAppData/universalResources"
    property path sourceRoot

    Depends{ name: "Qt.core" }
    readonly property path rccPath: Qt.core.binPath + "/rcc"

    Depends{ name: "FK.deploy" }

    Rule{
        inputs: ["fk.resource"]
        Artifact{
            filePath: input.FK.content.buildFolder                                                                                                              //root
                      + "/" + (input.FK.content.sourceRoot === undefined ? "."
                                                                         : FileInfo.path(FileInfo.relativePath(input.FK.content.sourceRoot, input.filePath)))   //relative path
                      + "/" + input.completeBaseName + ".rcc"                                                                                                   //file name
            fileTags: "fk.content"
            FK.content.location: input.FK.content.location
            FK.content.sourceRoot: input.FK.content.buildFolder
        }
        prepare: {
            var cmd = Command(input.content.rccPath, ["--binary", "--no-compress". input.filePath, "-o", output.filePath])
            cmd.description = "Compile resource " + input.filePath + " at " + output.filePath
            cmd.highlight = "filegen"
            return [cmd]
        }
    }

}

