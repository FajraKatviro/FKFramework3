import qbs

Product{
    Depends{ name: "FK.fileDeploy" }
    type: "fk.deployedFile"
    FK.fileDeploy.destinationRoot: utilsFolder
}
