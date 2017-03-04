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
