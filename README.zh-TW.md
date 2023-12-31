<!-- README in Traditional Chinese (README 繁體中文) -->

# Plot3d 輸出文件工具
這個工具是用於生成 Plot3d 文件的輸出，以便在相應的軟件中進行可視化。目前它支援卡式座標、結構網格功能。

功能特點
支援卡式座標：該工具可以生成 Plot3d 文件，用於描述具有卡式座標系統的數值場。這使得在支援 Plot3d 文件格式的軟件中進行數據可視化成為可能。

結構網格：該工具可以處理結構網格數據，並生成 Plot3d 文件以保存這些數據。結構網格由規則的網格單元構成，這使得在軟件中對數據進行網格化處理更加方便。

Head Only 輸出：這個工具可以生成只包含頭部信息的 Plot3d 文件。這意味著只生成描述數據結構、邊界條件等的元數據，而不包含實際的數據值。這對於測試和調試應用程序非常有用。


## 使用方法

參考 [Adapter (refactoring.guru)](https://refactoring.guru/design-patterns/adapter)
繼承 Data2D<T>. ( Data3D<T> for 3D) 

```cpp
template<typename T>
class YourData: public Data2D<T>{
 public:
  Mydata2D(int nx, int ny) : Data2D<T>(nx, ny) { }

  T &operator()(int i, int j) override{
      // TODO
  }
};
```
