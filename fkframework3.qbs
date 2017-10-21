import qbs
import qbs.Environment
import "features/qbs/scripts/fkframeworkpath.js" as FKPaths

Project{

    //minimumQbsVersion: "1.10.0"

    name: "FKFramework 3"

    references: [
        "features/features.qbs",
        "utils/utils.qbs"
    ]

    qbsSearchPaths: ["./features/qbs", "./qbs"]

    property string frameworkPath: FKPaths.frameworkPath(qbs.hostOS)

    Product{
        name: "Qbs configuration"
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
}
