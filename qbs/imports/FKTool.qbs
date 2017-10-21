import qbs

QtApplication{
    type: "fk.deployedFile"
    Depends{ name: "FK"; submodules: ["helpers", "deploy"] }
    FK.deploy.destinationRoot: utilsFolder
    FK.helpers.skipValidation: true
    FK.helpers.searchRoot: product.sourceDirectory
}
