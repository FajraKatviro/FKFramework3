import qbs

Product{

   Depends{ name: "FK.deploy" }
   type: "deployedPackage"
   FK.deploy.root: utilsFolder

}
