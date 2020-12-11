#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>

static const unsigned char qt_resource_tree[] = {
0,
0,0,0,0,2,0,0,0,2,0,0,0,1,0,0,0,
8,0,2,0,0,0,3,0,0,0,3,0,0,4,16,0,
0,0,0,0,1,0,0,0,0,0,0,0,20,0,2,0,
0,0,1,0,0,0,30,0,0,0,90,0,2,0,0,0,
1,0,0,0,29,0,0,0,146,0,2,0,0,0,2,0,
0,0,6,0,0,1,234,0,2,0,0,0,14,0,0,0,
15,0,0,0,184,0,2,0,0,0,7,0,0,0,8,0,
0,1,58,0,0,0,0,0,1,0,0,0,0,0,0,0,
236,0,0,0,0,0,1,0,0,0,0,0,0,0,198,0,
0,0,0,0,1,0,0,0,0,0,0,1,106,0,0,0,
0,0,1,0,0,0,0,0,0,1,196,0,0,0,0,0,
1,0,0,0,0,0,0,1,20,0,0,0,0,0,1,0,
0,0,0,0,0,1,154,0,0,0,0,0,1,0,0,0,
0,0,0,3,80,0,0,0,0,0,1,0,0,0,0,0,
0,2,226,0,0,0,0,0,1,0,0,0,0,0,0,2,
64,0,0,0,0,0,1,0,0,0,0,0,0,1,248,0,
0,0,0,0,1,0,0,0,0,0,0,2,104,0,0,0,
0,0,1,0,0,0,0,0,0,2,192,0,0,0,0,0,
1,0,0,0,0,0,0,3,192,0,0,0,0,0,1,0,
0,0,0,0,0,3,46,0,0,0,0,0,1,0,0,0,
0,0,0,3,120,0,0,0,0,0,1,0,0,0,0,0,
0,2,146,0,0,0,0,0,1,0,0,0,0,0,0,3,
150,0,0,0,0,0,1,0,0,0,0,0,0,3,224,0,
0,0,0,0,1,0,0,0,0,0,0,2,30,0,0,0,
0,0,1,0,0,0,0,0,0,3,8,0,0,0,0,0,
1,0,0,0,0,0,0,0,122,0,0,0,0,0,1,0,
0,0,0,0,0,0,58,0,0,0,0,0,1,0,0,0,
0};
static const unsigned char qt_resource_names[] = {
0,
1,0,0,0,47,0,47,0,3,0,0,120,60,0,113,0,
109,0,108,0,16,4,235,252,162,0,82,0,101,0,115,0,
111,0,117,0,114,0,99,0,101,0,80,0,114,0,111,0,
118,0,105,0,100,0,101,0,114,0,13,8,82,144,92,0,
82,0,101,0,115,0,111,0,117,0,114,0,99,0,101,0,
115,0,46,0,113,0,109,0,108,0,13,9,58,208,163,0,
83,0,116,0,121,0,108,0,101,0,83,0,101,0,116,0,
116,0,105,0,110,0,103,0,115,0,9,0,40,229,188,0,
83,0,116,0,121,0,108,0,101,0,46,0,113,0,109,0,
108,0,16,11,25,170,69,0,67,0,111,0,109,0,112,0,
111,0,110,0,101,0,110,0,116,0,115,0,77,0,111,0,
100,0,117,0,108,0,101,0,4,0,5,4,108,0,73,0,
109,0,112,0,108,0,16,12,140,233,124,0,70,0,117,0,
108,0,108,0,84,0,97,0,115,0,107,0,86,0,105,0,
101,0,119,0,46,0,113,0,109,0,108,0,17,6,61,91,
124,0,80,0,114,0,111,0,116,0,111,0,78,0,111,0,
116,0,101,0,86,0,105,0,101,0,119,0,46,0,113,0,
109,0,108,0,16,14,75,150,188,0,83,0,101,0,116,0,
116,0,105,0,110,0,103,0,115,0,77,0,101,0,110,0,
117,0,46,0,113,0,109,0,108,0,21,1,47,233,156,0,
80,0,114,0,111,0,116,0,111,0,78,0,111,0,116,0,
101,0,68,0,101,0,108,0,101,0,103,0,97,0,116,0,
101,0,46,0,113,0,109,0,108,0,21,13,48,33,92,0,
80,0,114,0,111,0,116,0,111,0,84,0,97,0,115,0,
107,0,68,0,101,0,108,0,101,0,103,0,97,0,116,0,
101,0,46,0,113,0,109,0,108,0,18,15,51,172,188,0,
80,0,114,0,111,0,116,0,111,0,84,0,97,0,115,0,
107,0,115,0,86,0,105,0,101,0,119,0,46,0,113,0,
109,0,108,0,16,13,120,117,124,0,70,0,117,0,108,0,
108,0,78,0,111,0,116,0,101,0,86,0,105,0,101,0,
119,0,46,0,113,0,109,0,108,0,4,0,4,136,149,0,
66,0,97,0,115,0,101,0,16,3,0,23,92,0,67,0,
104,0,97,0,110,0,103,0,101,0,66,0,117,0,116,0,
116,0,111,0,110,0,46,0,113,0,109,0,108,0,14,10,
146,127,124,0,66,0,97,0,115,0,101,0,66,0,117,0,
116,0,116,0,111,0,110,0,46,0,113,0,109,0,108,0,
17,2,248,27,252,0,66,0,97,0,115,0,101,0,80,0,
114,0,111,0,116,0,111,0,84,0,101,0,120,0,116,0,
46,0,113,0,109,0,108,0,18,3,19,37,220,0,68,0,
97,0,116,0,101,0,84,0,105,0,109,0,101,0,80,0,
105,0,99,0,107,0,101,0,114,0,46,0,113,0,109,0,
108,0,20,7,105,62,124,0,67,0,97,0,116,0,97,0,
108,0,111,0,103,0,117,0,101,0,79,0,118,0,101,0,
114,0,108,0,97,0,121,0,46,0,113,0,109,0,108,0,
14,4,18,125,188,0,77,0,101,0,110,0,117,0,66,0,
117,0,116,0,116,0,111,0,110,0,46,0,113,0,109,0,
108,0,16,2,32,225,252,0,68,0,101,0,108,0,101,0,
116,0,101,0,66,0,117,0,116,0,116,0,111,0,110,0,
46,0,113,0,109,0,108,0,16,13,226,137,156,0,68,0,
97,0,116,0,101,0,84,0,105,0,109,0,101,0,65,0,
114,0,101,0,97,0,46,0,113,0,109,0,108,0,14,4,
158,127,92,0,66,0,97,0,99,0,107,0,66,0,117,0,
116,0,116,0,111,0,110,0,46,0,113,0,109,0,108,0,
17,1,201,27,60,0,66,0,97,0,115,0,101,0,80,0,
114,0,111,0,116,0,111,0,86,0,105,0,101,0,119,0,
46,0,113,0,109,0,108,0,12,5,230,101,124,0,66,0,
97,0,115,0,101,0,84,0,101,0,120,0,116,0,46,0,
113,0,109,0,108,0,18,8,32,192,252,0,66,0,97,0,
115,0,101,0,72,0,101,0,97,0,100,0,101,0,114,0,
84,0,101,0,120,0,116,0,46,0,113,0,109,0,108,0,
13,4,48,112,92,0,65,0,100,0,100,0,66,0,117,0,
116,0,116,0,111,0,110,0,46,0,113,0,109,0,108,0,
21,9,108,33,28,0,66,0,97,0,115,0,101,0,80,0,
114,0,111,0,116,0,111,0,68,0,101,0,108,0,101,0,
103,0,97,0,116,0,101,0,46,0,113,0,109,0,108,0,
8,8,1,90,92,0,109,0,97,0,105,0,110,0,46,0,
113,0,109,0,108};
static const unsigned char qt_resource_empty_payout[] = { 0, 0, 0, 0, 0 };
QT_BEGIN_NAMESPACE
extern Q_CORE_EXPORT bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
QT_END_NAMESPACE
namespace QmlCacheGeneratedCode {
namespace _0x5f__main_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Base_BaseProtoDelegate_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Base_AddButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Base_BaseHeaderText_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Impl_FullNoteView_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Base_BaseText_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Base_BaseProtoView_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Impl_ProtoTasksView_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_StyleSettings_Style_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Impl_ProtoTaskDelegate_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Base_BackButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Base_DateTimeArea_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Impl_ProtoNoteDelegate_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Base_DeleteButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Impl_SettingsMenu_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ResourceProvider_Resources_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Base_MenuButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Base_CatalogueOverlay_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Impl_ProtoNoteView_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Base_DateTimePicker_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Base_BaseProtoText_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Base_BaseButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Impl_FullTaskView_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ComponentsModule_Base_ChangeButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
        resourcePathToCachedUnit.insert(QStringLiteral("/main.qml"), &QmlCacheGeneratedCode::_0x5f__main_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Base/BaseProtoDelegate.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Base_BaseProtoDelegate_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Base/AddButton.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Base_AddButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Base/BaseHeaderText.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Base_BaseHeaderText_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Impl/FullNoteView.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Impl_FullNoteView_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Base/BaseText.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Base_BaseText_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Base/BaseProtoView.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Base_BaseProtoView_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Impl/ProtoTasksView.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Impl_ProtoTasksView_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/StyleSettings/Style.qml"), &QmlCacheGeneratedCode::_qml_StyleSettings_Style_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Impl/ProtoTaskDelegate.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Impl_ProtoTaskDelegate_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Base/BackButton.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Base_BackButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Base/DateTimeArea.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Base_DateTimeArea_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Impl/ProtoNoteDelegate.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Impl_ProtoNoteDelegate_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Base/DeleteButton.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Base_DeleteButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Impl/SettingsMenu.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Impl_SettingsMenu_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ResourceProvider/Resources.qml"), &QmlCacheGeneratedCode::_qml_ResourceProvider_Resources_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Base/MenuButton.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Base_MenuButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Base/CatalogueOverlay.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Base_CatalogueOverlay_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Impl/ProtoNoteView.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Impl_ProtoNoteView_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Base/DateTimePicker.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Base_DateTimePicker_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Base/BaseProtoText.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Base_BaseProtoText_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Base/BaseButton.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Base_BaseButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Impl/FullTaskView.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Impl_FullTaskView_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ComponentsModule/Base/ChangeButton.qml"), &QmlCacheGeneratedCode::_qml_ComponentsModule_Base_ChangeButton_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.version = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
QT_PREPEND_NAMESPACE(qRegisterResourceData)(/*version*/0x01, qt_resource_tree, qt_resource_names, qt_resource_empty_payout);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qml)() {
    ::unitRegistry();
    Q_INIT_RESOURCE(qml_qmlcache);
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qml))
int QT_MANGLE_NAMESPACE(qCleanupResources_qml)() {
    Q_CLEANUP_RESOURCE(qml_qmlcache);
    return 1;
}
