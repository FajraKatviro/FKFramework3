# FKFramework3

Проект представляет собой набор средств для создания мультиплеерных игр на основе QML и Qt3D

Целью проекта не явлется написание ещё одного слоя абстракции вокруг Qt. Напротив, сюда будут включаться только решения, для которых не существует реализации в самом Qt (в первую очередь, сетевое взаимодействие и синхронизация объектов из QML-контекста)

Схема разработки проекта:

| № п\п |Подпроект|Тип|Статус|Раздел|
|---|---|---|---|---|
|1|FKNetwork|module|In progress|components
|2|FKUpdate|module|Pending|components
|3|FKBootstrapper|module|Pending|utils
|4|FKTools|apps|Pending migration|tools
|5|FKUtils|sources|Pending migration|utils
|6|FKServer|module|Pending|components
|7|FKClient|module|Pending|components
|8|FKLudo|module|Pending|components
|9|FKSamples|apps|Pending|samples


Building:

  1. Clone repository with --recursive option
  2. Configure root project (FKFramework.pro) with QtCreator
    1. Add 'make install' step after 'make' step
    2. **(windows only)** add 'make deploy' step after 'make install' step
  3. Build

Framework binaries and source components are placed to default installation folder ($HOME/Applications/FKFramework for mac, $HOME/FKFramework for other unix, %HOMEPATH%\AppData\Roaming\FKFramework for windows)


Integration:

  1. Add to you project submodule https://github.com/FajraKatviro/FKDefaultPaths.git
  2. Include 'fkframework.pri' file from submodule to the end of your project file
