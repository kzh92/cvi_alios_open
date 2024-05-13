#ifndef CXVISION_TEST_PLUGINS_DATA_INPUT_H_
#define CXVISION_TEST_PLUGINS_DATA_INPUT_H_

#include <cxvision/cxvision.h>

namespace demo {

class DataInput final : public cx::PluginBase {
public:
  bool Init(const std::map<std::string, std::string>& props) override;
  bool DeInit() override;
  bool Process(const std::vector<cx::BufferPtr>& bufferVec) override;
};

}  // namespace demo

#endif  // CXVISION_TEST_PLUGINS_DATA_INPUT_H_