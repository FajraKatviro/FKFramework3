import qbs
import qbs.Environment
import "paths/fkframework.js" as FKPaths

Project{

    minimumQbsVersion: "1.9.1"

    name: "FKFramework 3"

    references: [
        "features/features.qbs"//,
        //"utils/utils.qbs"
    ]

    qbsSearchPaths: "."

    Product{
        name: "Other files"
        files: [
            "README.md",
            "LICENSE",
            "paths/README.md",
            "paths/fkframeworkpath.pri",
            "paths/fkframework.pri"
        ]
    }

    property string frameworkPath: FKPaths.frameworkPath(qbs.hostOS)

    Product{
        type: ["searchPathsConfiguration"]
        Depends{ name: "Qt.core" }
        readonly property string qbsPath: Qt.core.binPath + "/../../../Tools/QtCreator/bin/qbs"
        Rule{
            multiplex: true
            alwaysRun: true
            Artifact {
                filePath: "searchPathsConfiguration.txt"
                fileTags: "searchPathsConfiguration"
            }
            prepare: {
                var cmd = new Command(product.qbsPath, ["config", "preferences.qbsSearchPaths", project.frameworkPath + "/qbs" ]);
                cmd.description = "added qbs search path " + project.frameworkPath + "/qbs"
                return [cmd];
            }
        }
    }
}
