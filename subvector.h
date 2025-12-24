#include <cstdint>
#include <stdexcept>
#include <new>

class Subvector {
 public:
  Subvector();
  bool PushBack(int32_t value);
  int32_t PopBack();
  bool Resize(uint32_t new_capacity);
  void ShrinkToFit();
  void Clear();
  Subvector& operator=(const Subvector& array);
  Subvector& operator=(Subvector&& array) noexcept;
  Subvector(const Subvector& array);
  Subvector(Subvector&& array) noexcept;
  ~Subvector();
  
 private:
  int32_t *mas_;
  uint32_t top_;
  uint32_t capacity_;
};
