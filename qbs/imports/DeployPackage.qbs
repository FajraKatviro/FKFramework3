import qbs

Product{
    Depends{ name: "FK.deploy" }
    type: "fk.deployedFile"
    FK.deploy.destinationRoot: utilsFolder
}
