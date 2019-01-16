#-------------------------------------------------
#
# Project created by QtCreator 2019-01-16T09:19:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFlareEngine
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Utils.cpp \
    Animation.cpp \
    AnimationSet.cpp \
    AnimationManager.cpp \
    AStarNode.cpp \
    AStarContainer.cpp \
    EffectManager.cpp \
    EventManager.cpp \
    Stats.cpp \
    StatBlock.cpp \
    Entity.cpp \
    Avatar.cpp \
    Enemy.cpp \
    EnemyBehavior.cpp \
    BehaviorStandard.cpp \
    BehaviorAlly.cpp \
    CampaignManager.cpp \
    ItemManager.cpp \
    CombatText.cpp \
    CursorManager.cpp \
    DeviceList.cpp \
    EnemyGroupManager.cpp \
    EngineSettings.cpp \
    Widget.cpp \
    WidgetLabel.cpp \
    FileParser.cpp \
    FontEngine.cpp \
    GameSlotPreview.cpp \
    GameState.cpp \
    WidgetTooltip.cpp \
    TooltipData.cpp \
    GameStateConfig.cpp \
    GameStateCutscene.cpp \
    GameStateLoad.cpp \
    GameStateNew.cpp \
    GameStatePlay.cpp \
    GameStateTitle.cpp \
    GameSwitcher.cpp \
    GetText.cpp \
    Hazard.cpp \
    HazardManager.cpp \
    IconManager.cpp \
    InputState.cpp \
    ItemStorage.cpp \
    Loot.cpp \
    LootManager.cpp \
    Map.cpp \
    MapCollision.cpp \
    MapParallax.cpp \
    MapRenderer.cpp \
    TileSet.cpp \
    Menu.cpp \
    MenuActionBar.cpp \
    MenuActiveEffects.cpp \
    MenuBook.cpp \
    MenuCharacter.cpp \
    MenuConfig.cpp \
    MenuConfirm.cpp \
    MenuDevConsole.cpp \
    MenuEnemy.cpp \
    MenuExit.cpp \
    MenuHUDLog.cpp \
    MenuInventory.cpp \
    MenuItemStorage.cpp \
    MenuLog.cpp \
    WidgetLog.cpp \
    MenuManager.cpp \
    MenuMiniMap.cpp \
    MenuNumPicker.cpp \
    MenuPowers.cpp \
    MenuStash.cpp \
    MenuStatBar.cpp \
    MenuTalker.cpp \
    MenuTouchControls.cpp \
    MenuVendor.cpp \
    MessageEngine.cpp \
    ModManager.cpp \
    NPC.cpp \
    NPCManager.cpp \
    Platform.cpp \
    PowerManager.cpp \
    QuestLog.cpp \
    RenderDevice.cpp \
    SaveLoad.cpp \
    SDLFontEngine.cpp \
    SDLHardwareImage.cpp \
    SDLInputState.cpp \
    SDLSoftwareRenderDevice.cpp \
    SDLSoundManager.cpp \
    SoundManager.cpp \
    Settings.cpp \
    SharedGameResources.cpp \
    SharedResources.cpp \
    Subtitles.cpp \
    TooltipManager.cpp \
    UtilsDebug.cpp \
    UtilsFileSystem.cpp \
    UtilsMath.cpp \
    UtilsParsing.cpp

HEADERS  += MainWindow.h \
    CommonIncludes.h \
    Utils.h \
    Animation.h \
    AnimationSet.h \
    AnimationManager.h \
    AStarNode.h \
    AStarContainer.h \
    EffectManager.h \
    EventManager.h \
    Stats.h \
    StatBlock.h \
    Entity.h \
    Avatar.h \
    Enemy.h \
    EnemyBehavior.h \
    BehaviorStandard.h \
    BehaviorAlly.h \
    CampaignManager.h \
    ItemManager.h \
    CombatText.h \
    CursorManager.h \
    DeviceList.h \
    EnemyGroupManager.h \
    EngineSettings.h \
    Widget.h \
    WidgetLabel.h \
    FileParser.h \
    FontEngine.h \
    GameSlotPreview.h \
    GameState.h \
    WidgetTooltip.h \
    TooltipData.h \
    GameStateConfig.h \
    GameStateCutscene.h \
    GameStateLoad.h \
    GameStateNew.h \
    GameStatePlay.h \
    GameStateTitle.h \
    GameSwitcher.h \
    GetText.h \
    Hazard.h \
    HazardManager.h \
    IconManager.h \
    InputState.h \
    ItemStorage.h \
    Loot.h \
    LootManager.h \
    Map.h \
    MapCollision.h \
    MapParallax.h \
    MapRenderer.h \
    TileSet.h \
    Menu.h \
    MenuActionBar.h \
    MenuActiveEffects.h \
    MenuBook.h \
    MenuCharacter.h \
    MenuConfig.h \
    MenuConfirm.h \
    MenuDevConsole.h \
    MenuEnemy.h \
    MenuExit.h \
    MenuHUDLog.h \
    MenuInventory.h \
    MenuItemStorage.h \
    MenuLog.h \
    WidgetLog.h \
    MenuManager.h \
    MenuMiniMap.h \
    MenuNumPicker.h \
    MenuPowers.h \
    MenuStash.h \
    MenuStatBar.h \
    MenuTalker.h \
    MenuTouchControls.h \
    MenuVendor.h \
    MessageEngine.h \
    ModManager.h \
    NPC.h \
    NPCManager.h \
    Platform.h \
    PowerManager.h \
    QuestLog.h \
    RenderDevice.h \
    SaveLoad.h \
    SDLFontEngine.h \
    SDLHardwareImage.h \
    SDLInputState.h \
    SDLSoftwareRenderDevice.h \
    SDLSoundManager.h \
    SoundManager.h \
    Settings.h \
    SharedGameResources.h \
    SharedResources.h \
    Subtitles.h \
    TooltipManager.h \
    UtilsDebug.h \
    UtilsFileSystem.h \
    UtilsMath.h \
    UtilsParsing.h

FORMS    += MainWindow.ui



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/dependecy/SDL/lib/ -llibSDL2 -llibSDL2_ttf -llibSDL2_mixer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/dependecy/SDL/lib/ -llibSDL2  -llibSDL2_ttf -llibSDL2_mixer
else:unix: LIBS += -L$$PWD/dependecy/SDL/lib/ -llibSDL2.dll -llibSDL2_ttf.dll

INCLUDEPATH += $$PWD/dependecy/SDL/include
DEPENDPATH += $$PWD/dependecy/SDL/bin
