#include "pch.h"

#include "./stringstream_adapter.h"
#include "../../util/util.h"
#include "../../exception/unsupported_operation_exception.h"

namespace casbin {


StringstreamAdapter :: StringstreamAdapter(std::stringstream && policy){
    this->m_policy_stringstream = std::move(policy);
}

void StringstreamAdapter :: LoadPolicy(const std::shared_ptr<Model>& model) {
    this->LoadPolicyStringStream(model, LoadPolicyLine);
}

void StringstreamAdapter :: LoadPolicyStringStream(const std::shared_ptr<Model>& model, 
                                                   std::function<void(std::string, const std::shared_ptr<Model>&)> handler) { 
    std::string line;
    while(getline(this->m_policy_stringstream, line, '\n')){
        line = Trim(line);
        handler(line, model);
    }

    this->m_policy_stringstream.str(std::string());
}



void StringstreamAdapter ::SavePolicy(const std::shared_ptr<Model>& model){
    throw UnsupportedOperationException("not implemented");
}
    
void StringstreamAdapter ::AddPolicy(std::string sec, std::string p_type, std::vector<std::string> rule){
    throw UnsupportedOperationException("not implemented");
}
    
void StringstreamAdapter ::RemovePolicy(std::string sec, std::string p_type, std::vector<std::string> rule){
    throw UnsupportedOperationException("not implemented");
}
    
void StringstreamAdapter ::RemoveFilteredPolicy(std::string sec, std::string ptype, int field_index, std::vector<std::string> field_values){
    throw UnsupportedOperationException("not implemented");
}

bool StringstreamAdapter ::IsFiltered(){
    throw UnsupportedOperationException("not implemented");
    return false;
}



} // namespace casbin



