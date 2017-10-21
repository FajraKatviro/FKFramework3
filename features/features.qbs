import qbs
import "qbs/scripts/fkframeworkpath.js" as FKPaths

Project{

    DeployPackage{
        name: "features for qmake"
        Group{
            files: "fkfeatures.pri"
            fileTags: ["fk.deployable"]
        }
        FK.fileDeploy.destinationRoot: FKPaths.frameworkPath(qbs.hostOS)
    }

    DeployPackage{
        name: "features for qbs"
        Group{
            files: "qbs/**"
            fileTags: ["fk.deployable"]
        }
        FK.fileDeploy.destinationRoot: FKPaths.frameworkPath(qbs.hostOS)
    }

}
