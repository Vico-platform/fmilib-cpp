
#ifndef FMILIBCPP_FMI1_FMU_HPP
#define FMILIBCPP_FMI1_FMU_HPP

#include "../fmicontext.hpp"

#include "fmilibcpp/fmu.hpp"
#include "fmilibcpp/util/temp_dir.hpp"

#include <fmilib.h>

namespace fmilibcpp
{

class fmi1_fmu : public fmu
{

private:
    fmi1_import_t* handle_;
    std::shared_ptr<fmicontext> ctx_;

    const bool fmiLogging_;
    const model_description md_;
    std::shared_ptr<temp_dir> tmpDir_;

public:
    fmi1_fmu(std::unique_ptr<fmicontext> ctx, std::shared_ptr<temp_dir> tmpDir, bool fmiLogging = true);

    [[nodiscard]] const model_description& get_model_description() const override;

    std::unique_ptr<slave> new_instance(const std::string& instanceName) override;

    ~fmi1_fmu() override;
};

} // namespace fmilibcpp

#endif // FMILIBCPP_FMI1_FMU_HPP