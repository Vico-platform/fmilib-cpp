
#ifndef FMILIBCPP_FMI2_SLAVE_HPP
#define FMILIBCPP_FMI2_SLAVE_HPP

#include "../fmicontext.hpp"
#include "fmi2_model_description.hpp"

#include <fmilibcpp/slave.hpp>
#include <fmilibcpp/util/temp_dir.hpp>

#include <fmilib.h>
#include <memory>

namespace fmilibcpp
{

class fmi2_slave : public slave
{
private:
    fmi2_import_t* handle_;
    const model_description md_;
    std::shared_ptr<fmicontext> ctx_;
    std::shared_ptr<temp_dir> tmpDir_;

public:
    fmi2_slave(
        const std::shared_ptr<fmicontext>& ctx,
        const std::string& instanceName,
        model_description md,
        std::shared_ptr<temp_dir> tmpDir);

    [[nodiscard]] const model_description& get_model_description() const override;
    bool setup_experiment(double start_time, double stop_time, double tolerance) override;

    bool enter_initialization_mode() override;
    bool exit_initialization_mode() override;
    bool step(double current_time, double step_size) override;

    bool terminate() override;
    bool reset() override;

    bool get_integer(const std::vector<value_ref>& vr, std::vector<int>& values) override;
    bool get_real(const std::vector<value_ref>& vr, std::vector<double>& values) override;
    bool get_string(const std::vector<value_ref>& vr, std::vector<std::string>& values) override;
    bool get_boolean(const std::vector<value_ref>& vr, std::vector<bool>& values) override;

    bool set_integer(const std::vector<value_ref>& vr, const std::vector<int>& values) override;
    bool set_real(const std::vector<value_ref>& vr, const std::vector<double>& values) override;
    bool set_string(const std::vector<value_ref>& vr, const std::vector<std::string>& values) override;
    bool set_boolean(const std::vector<value_ref>& vr, const std::vector<bool>& values) override;

    ~fmi2_slave() override;
};

} // namespace fmilibcpp

#endif //FMILIBCPP_FMI2_SLAVE_HPP
