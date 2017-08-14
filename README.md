# FKFramework3

Проект представляет собой набор средств для создания мультиплеерных игр на основе QML и Qt3D

Целью проекта не явлется написание ещё одного слоя абстракции вокруг Qt. Напротив, сюда будут включаться только решения, для которых не существует реализации в самом Qt (в первую очередь, сетевое взаимодействие и синхронизация объектов из QML-контекста)

Схема разработки проекта:

| № п\п |Component|Section|Impl|Util|Test|Doc|Description|
|---|---|---|:---:|:---:|:---:|:---:|---|
|1|mobile|Features|:white_check_mark:|:white_check_mark:|:clock10:|[doc](features/README.md#L9)|Набор средств для упрощения настройки qmake-проекта для мобильных платформ|
|2|deploy|Features|:white_check_mark:|:white_check_mark:|:clock10:|[doc](features/README.md#L25)|Набор средств для создания установочных дистрибутивов для десктопных платформ|
|3|imageset|Features|:white_check_mark:|:white_check_mark:|:clock10:|[doc](features/README.md#L60)|Набор средств для создания ресурсов изображений под различные разрешения экрана|
|4|content|Features|:white_check_mark:|:white_check_mark:|:clock10:|[doc](features/README.md#L67)|Набор средств для упаковки немасштабируемого контента|
|5|modules|Features|:clock10:|:white_check_mark:|:clock10:|:clock10:|Набор средств для подключения FKFramework-модулей|
|6|helpers|Features|:white_check_mark:|:white_check_mark:|:clock10:|[src](utils/helpers)|Набор заголовочных файлов, содержащих ряд полезных функций|
|7|ImageManager|Utils|:white_check_mark:|:white_check_mark:|:clock10:|[doc](utils/PackageManager/README.md)|Графический клиент для управления наборами изображений|
|8|PackageGenerator|Utils|:arrows_counterclockwise:|:white_check_mark:|:clock10:|[doc](utils/PackageManager/README.md)|Приложение для сборки ресурсов под различные разрешения экрана на основе файлов конфигурации набора изображений|
|9|PackageManager|Utils|:white_check_mark:|:white_check_mark:|:clock10:|[doc](utils/PackageManager/README.md)|Приложение для управления файлами конфигурации наборов изображений под различные разрешения экрана|
|10|DeployQML|Utils|:clock10:|:clock10:|:clock10:|:clock10:|Вспомогательное приложение для копирования QML-зависимостей при создании deb-пакета (invalid)|
|11|Bootstrapper|Utils|:clock10:|:clock10:|:clock10:|:clock10:|Готовый клиент для загрузки приложений через модуль обновления|
|12|Network|Modules|:arrows_counterclockwise:|:clock10:|:clock10:|:clock10:|Базовые компоненты для сетевого взаимодействия|
|13|Update|Modules|:clock10:|:clock10:|:clock10:|:clock10:|Компоненты для проверки наличия, скачивания и применения обновлений|
|14|Server|Modules|:clock10:|:clock10:|:clock10:|:clock10:|Конфигурация сетевых компонентов для создания сервера|
|15|Client|Modules|:clock10:|:clock10:|:clock10:|:clock10:|Конфигурация сетевых компонентов для создания клиента|
|16|Ludo|Modules|:clock10:|:clock10:|:clock10:|:clock10:|Конфигурация сетевых компонентов для создания многопользовательской игры|
|17|samples|Samples|:clock10:|:clock10:|:clock10:|:clock10:|Примеры использования модулей|


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

**Project structure:**

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
