#pragma once
#include <Control/DefaultEffectItem.hpp>
#include <Effect/EffectFactory.hpp>
#include <JS/JSProcessMetadata.hpp>
#include <JS/JSProcessModel.hpp>
#include <Process/GenericProcessFactory.hpp>
#include <Process/ProcessFactory.hpp>
#include <Process/Script/ScriptEditor.hpp>
#include <Process/WidgetLayer/WidgetProcessFactory.hpp>

namespace JS
{
struct LanguageSpec
{
  static constexpr const char* language = "JS";
};

using ProcessFactory = Process::ProcessFactory_T<JS::ProcessModel>;
using LayerFactory = Process::EffectLayerFactory_T<
    ProcessModel,
    Process::DefaultEffectItem,
    Process::ProcessScriptEditDialog<
        ProcessModel,
        ProcessModel::p_script,
        LanguageSpec>>;
}
