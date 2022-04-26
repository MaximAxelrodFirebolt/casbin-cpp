#pragma once

#include "../adapter.h"

namespace casbin {

class StringstreamAdapter: public Adapter {
    public:

        virtual ~StringstreamAdapter(){}

        StringstreamAdapter(std::stringstream && policy);

        void LoadPolicy(const std::shared_ptr<Model>& model) override;

        void SavePolicy(const std::shared_ptr<Model>& model) override;
        
        void AddPolicy(std::string sec, std::string p_type, std::vector<std::string> rule) override;
        
        void RemovePolicy(std::string sec, std::string p_type, std::vector<std::string> rule) override;
        
        void RemoveFilteredPolicy(std::string sec, std::string ptype, int field_index, std::vector<std::string> field_values) override;
        
        bool IsFiltered() override;

    private:
        void LoadPolicyStringStream(const std::shared_ptr<Model>& model, 
            std::function<void(std::string, const std::shared_ptr<Model>&)> handler);
};

} // namespace casbin
