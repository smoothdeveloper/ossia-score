#include "AutomationLayerModel.hpp"
#include "AutomationModel.hpp"
#include <Curve/Process/CurveProcessPanelProxy.hpp>
#include <Process/LayerModel.hpp>

class QObject;
#include <iscore/tools/SettableIdentifier.hpp>

// TODO refactor with mapping ?
namespace Automation
{
LayerModel::LayerModel(
        ProcessModel& model,
        const Id<Process::LayerModel>& id,
        QObject* parent) :
    Process::LayerModel {
        id,
        Metadata<ObjectKey_k, LayerModel>::get(),
        model,
        parent}
{

}

LayerModel::LayerModel(
        const LayerModel& source,
        ProcessModel& model,
        const Id<Process::LayerModel>& id,
        QObject* parent) :
    Process::LayerModel {
        id,
        Metadata<ObjectKey_k, LayerModel>::get(),
        model,
        parent}
{
    // Nothing to copy
}

Process::LayerModelPanelProxy* LayerModel::make_panelProxy(
        QObject* parent) const
{
    return new Curve::CurveProcessPanelProxy<LayerModel>{*this, parent};
}

void LayerModel::serialize(
        const VisitorVariant&) const
{
    // Nothing to save
}

const ProcessModel& LayerModel::model() const
{
    return static_cast<const ProcessModel&>(processModel());
}
}
