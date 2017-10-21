import qbs

Product{
    Depends{ name: "FK.fileDeploy" }
    type: "fk.deployedFile"
    property path deployFolder: utilsFolder
}
