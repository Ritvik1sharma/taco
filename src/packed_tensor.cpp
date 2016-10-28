#include "packed_tensor.h"

#include <iostream>
#include <string>

#include "util/strings.h"

using namespace std;

namespace taco {

std::ostream& operator<<(std::ostream& os, const PackedTensor& tp) {
  auto& indices = tp.getIndices();
  auto& values  = tp.getValues();
  auto nnz      = tp.getNnz();

  // Print indices
  for (size_t i=0; i < indices.size(); ++i) {
    auto& index = indices[i];
    os << "L" << to_string(i) << ":" << std::endl;
    for (size_t j=0; j < index.size(); ++j) {
      auto& indexArray = index[j];
      os << "  {" << util::join(indexArray) << "}" << std::endl;
    }
  }

  //  // Print values
  os << "values:" << std::endl << "  {" << util::join(values, values+nnz) << "}";

  return os;
}

}
