#pragma once
#include <iscore/tools/IdentifiedObject.hpp>

class ProcessSharedModelInterface;
class ProcessViewModelPanelProxy;

/**
 * @brief The ProcessViewModelInterface class
 *
 * Interface to implement to make a process view model.
 */
class ProcessViewModelInterface: public IdentifiedObject<ProcessViewModelInterface>
{
    public:
        ProcessSharedModelInterface& sharedProcessModel() const;

        virtual void serialize(const VisitorVariant&) const = 0;
        virtual ProcessViewModelPanelProxy* make_panelProxy(QObject* parent) const = 0;


    protected:
        ProcessViewModelInterface(const id_type<ProcessViewModelInterface>& viewModelId,
                                  const QString& name,
                                  ProcessSharedModelInterface& sharedProcess,
                                  QObject* parent);

        template<typename Impl>
        ProcessViewModelInterface(Deserializer<Impl>& vis,
                                  ProcessSharedModelInterface& sharedProcess,
                                  QObject* parent) :
            IdentifiedObject<ProcessViewModelInterface> {vis, parent},
            m_sharedProcessModel {sharedProcess}
        {
            // Nothing else to load
        }

    private:
        ProcessSharedModelInterface& m_sharedProcessModel;
};


/**
 * @brief model Returns the casted version of a shared model given a view model.
 * @param viewModel A view model which has a directive "using model_type = MySharedModelType;" in its class body
 *
 * @return a pointer of the correct type.
 */
template<typename T>
const typename T::model_type* model(const T* viewModel)
{
    return static_cast<const typename T::model_type*>(viewModel->sharedProcessModel());
}


template<typename T>
const typename T::model_type& model(const T& viewModel)
{
    return static_cast<const typename T::model_type&>(viewModel.sharedProcessModel());
}

/**
 * @brief identifierOfViewModelFromSharedModel
 * @param pvm A process view model
 *
 * @return A tuple which contains the required identifiers to get from a shared model to a given view model
 *  * The box identifier
 *  * The deck identifier
 *  * The view model identifier
 */
// TODO this should be in DeckModel.hpp instead; makes no sense here.
std::tuple<int, int, int> identifierOfProcessViewModelFromConstraint(ProcessViewModelInterface* pvm);

QDataStream& operator<< (QDataStream& s, const std::tuple<int, int, int>& tuple);
QDataStream& operator>> (QDataStream& s, std::tuple<int, int, int>& tuple);
