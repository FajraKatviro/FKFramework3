# FKFramework3

Проект представляет собой набор средств для создания мультиплеерных игр на основе QML и Qt3D

Целью проекта не явлется написание ещё одного слоя абстракции вокруг Qt. Напротив, сюда будут включаться только решения, для которых не существует реализации в самом Qt (в первую очередь, сетевое взаимодействие и синхронизация объектов из QML-контекста)

Схема разработки проекта:

| № п\п |Подпроект|Статус|Секция|Описание|
|---|---|---|---|---|
|1|FKNetwork|In progress|modules|Базовые компоненты для сетевого взаимодействия|
|2|FKUpdate|Pending|modules|Компоненты для проверки наличия, скачивания и применения обновлений|
|3|FKBootstrapper|Pending|tools|Готовый клиент для загрузки приложений через модуль обновления|
|4|FKTools|In progress|tools|Набор вспомогательных инструментов для разработки|
|5|FKUtils|Testing|utils|Набор вспомогательных инструментов для интеграции в проект|
|6|FKServer|Pending|modules|Конфигурация сетевых компонентов для создания сервера|
|7|FKClient|Pending|modules|Конфигурация сетевых компонентов для создания клиента|
|8|FKLudo|Pending|modules|Конфигурация сетевых компонентов для создания многопользовательской игры|
|9|FKSamples|Pending|samples|Примеры использования модулей|


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
  3. Enable required features (see utils section)

**Full description:**

**Paths section**

This section is a separate git repository. The repository contains *.pri* files with default pre-defined locations for FKFramework3 related files.
- FK_FRAMEWORK_PATH - FKFramework3 root directory
- FK_TOOLS_FOLDER - Tools section directory
- FK_UTILS_FOLDER - Utils section directory

Include 'fkframeworkpath.pri' to get these values or include 'fkframework.pri' to use utils section
If you want override used FKFramework3 location, you should set FK_FRAMEWORK_PATH variable before include command. So, there is the best place for include command at the end of project file.

**Tools section**

This section uncludes the set of tools designed for different develop or deploy automatisations. 
- deploy_desktop
- deploy_mobile
- helpers
- imagesetGenerator

**Utils section**

This section provides the set of *.pri* files for enabling FKFramework3 features. 
Add value to FK variable (e.g. FK += imageset) to enable feature
- helpers - set of common used headers (see sources for details)
- deploy
- mobile
- imageset
- modules

**Modules section**

**Samples section**
