# FKFramework3

This project is a toolset for multiplayer game creation with QML and Qt3D

It is not a one more game engine. The main purpose of this project is adding of some important game-related features missed in Qt (generally, QML-objects network interactions and syncronisations)

**Project structure:**

| №№ |Component|Section|Impl|Util|Test|Doc|Description|
|---|---|---|:---:|:---:|:---:|:---:|---|
|1|:key: mobile|Features|:white_check_mark:|:white_check_mark:|:clock10:|[doc](features/README.md#L9)|Набор средств для упрощения настройки qmake-проекта для мобильных платформ|
|2|:key: deploy|Features|:white_check_mark:|:white_check_mark:|:clock10:|[doc](features/README.md#L25)|Набор средств для создания установочных дистрибутивов для десктопных платформ|
|3|:key: imageset|Features|:white_check_mark:|:white_check_mark:|:clock10:|[doc](features/README.md#L60)|Набор средств для создания ресурсов изображений под различные разрешения экрана|
|4|:key: content|Features|:white_check_mark:|:white_check_mark:|:clock10:|[doc](features/README.md#L67)|Набор средств для упаковки немасштабируемого контента|
|5|:key: modules|Features|:clock10:|:white_check_mark:|:clock10:|:clock10:|Набор средств для подключения FKFramework-модулей|
|6|:key: helpers|Features|:white_check_mark:|:white_check_mark:|:clock10:|[src](utils/helpers)|Набор заголовочных файлов, содержащих ряд полезных функций|
|***|*****************|**********|*****|*****|*****|*****|********************************|
|7|:wrench: Image Manager|Utils|:white_check_mark:|:white_check_mark:|:clock10:|[doc](utils/PackageManager/README.md)|Графический клиент для управления наборами изображений|
|8|:wrench: Package Generator|Utils|:arrows_counterclockwise:|:white_check_mark:|:clock10:|[doc](utils/PackageManager/README.md)|Приложение для сборки ресурсов под различные разрешения экрана на основе файлов конфигурации набора изображений|
|9|:wrench: Package Manager|Utils|:white_check_mark:|:white_check_mark:|:clock10:|[doc](utils/PackageManager/README.md)|Приложение для управления файлами конфигурации наборов изображений под различные разрешения экрана|
|10|:wrench: Bootstrapper|Utils|:clock10:|:clock10:|:clock10:|:clock10:|Готовый клиент для загрузки приложений через модуль обновления|
|***|*****************|**********|*****|*****|*****|*****|********************************|
|11|:package: Network|Modules|:arrows_counterclockwise:|:clock10:|:clock10:|:clock10:|Базовые компоненты для сетевого взаимодействия|
|12|:package: Update|Modules|:clock10:|:clock10:|:clock10:|:clock10:|Компоненты для проверки наличия, скачивания и применения обновлений|
|13|:package: Server|Modules|:clock10:|:clock10:|:clock10:|:clock10:|Конфигурация сетевых компонентов для создания сервера|
|14|:package: Client|Modules|:clock10:|:clock10:|:clock10:|:clock10:|Конфигурация сетевых компонентов для создания клиента|
|15|:package: Ludo|Modules|:clock10:|:clock10:|:clock10:|:clock10:|Конфигурация сетевых компонентов для создания многопользовательской игры|
|***|*****************|**********|*****|*****|*****|*****|********************************|
|16|:steam_locomotive: samples|Samples|:clock10:|:clock10:|:clock10:|:clock10:|Примеры использования модулей|


Building:

  1. Clone repository with --recursive option
  2. Configure root project (FKFramework.pro) with QtCreator
  3. Add 'make deploy' step after 'make' step
  4. Build

Framework binaries and source components are placed to default installation folder ($HOME/Applications/FKFramework for mac, $HOME/FKFramework for other unix, %HOMEPATH%\AppData\Roaming\FKFramework for windows)


Integration:

  1. Add to you project submodule https://github.com/FajraKatviro/FKDefaultPaths.git
  2. Include 'fkframework.pri' file from submodule to the end of your project file
  3. Enable required features (see features section)
  4. Add 'make fkpreprocess' step before 'make' step
  5. Add 'make fkpostprocess' step after 'make' step



**Overview:**

**Paths section**

This section is a separate git repository. The repository contains *.pri* files with default pre-defined locations for FKFramework3 related files.
- FK_FRAMEWORK_PATH - FKFramework3 root directory
- FK_UTILS_FOLDER - Utils section directory

Include 'fkframeworkpath.pri' to get these values or include 'fkframework.pri' to use fkfeatures.
If you want override used FKFramework3 location, you should set FK_FRAMEWORK_PATH variable before include command. So, there is the best place for include command at the end of project file.

**Features section**

This section provides the set of *.pri* files for enabling FKFramework3 features.
Add value to FK variable (e.g. FK += imageset) to enable feature.
See content table for avaliable utils.
Some features are separate build steps. They are included to fkpre(post)process build steps. You can invoke them separately if disable default build steps (see [fkfeatures.pri](features/fkfeatures.pri) for details)

**Utils section**

This section includes the set of utils designed for different develop or deploy automatisations.
See content table for utils description.

**Modules section**

This section contains the set of QML plugins for application development.
See content table for avaliable modules and detailed description.

**Samples section**

This section contains the set of FKFramework-based application samples.
See source code for details.
