import qbs
import "qbs/scripts/fkframeworkpath.js" as FKPaths

Project{

    DeployPackage{
        name: "features for qmake"
        files: "README.md"
        Group{
            files: "fkfeatures.pri"
            fileTags: ["fk.deployable"]
        }
        deployFolder: FKPaths.frameworkPath(qbs.hostOS)
    }

    DeployPackage{
        name: "features for qbs"
        files: "README.qbs.md"
        Group{
            files: "qbs/**"
            fileTags: ["fk.deployable"]
        }
        deployFolder: FKPaths.frameworkPath(qbs.hostOS)
    }

}
