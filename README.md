# pga-point-cloud-registration
High-Performance PGA-Based Point Cloud Registration Engine - Sub-5ms ICP solver using dual quaternions (Motors) in Cl(3,0,1) with AVX2 SIMD acceleration
## 🛠️ Building & Testing

### 1. Running Unit Tests
To verify PGA Motor kinematics and analytical Jacobian logic:
```bash
mkdir build && cd build
cmake .. -DBUILD_TESTS=ON
make
ctest --output-on-failure
2. Running Minimal Working Example (MWE)
To execute the high-throughput point cloud alignment demo:
mkdir build && cd build
cmake ..
make pga_mwe_demo
./examples/pga_mwe_demo
3. ROS 2 Node Integration
To build and launch the registration node within a ROS 2 workspace:
cd ~/ros2_ws/src
ln -s /path/to/pga-point-cloud-registration ros2_pga
cd ~/ros2_ws
colcon build --packages-select pga_point_cloud_registration
source install/setup.bash
ros2 run pga_point_cloud_registration pga_registration_node

---
