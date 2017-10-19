import qbs
import "qbs/scripts/fkframeworkpath.js" as FKPaths

Project{

    DeployPackage{
        name: "features for qmake"
        Group{
            files: "fkfeatures.pri"
            fileTags: ["deployable"]
        }
        FK.deploy.root: FKPaths.frameworkPath(qbs.hostOS)
    }

    DeployPackage{
        name: "features for qbs"
        Group{
            files: "qbs/**"
            fileTags: ["deployable"]
        }
        FK.deploy.root: FKPaths.frameworkPath(qbs.hostOS)
    }

}
