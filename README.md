### 整个补丁完全以AI生成

### 指纹修改清单 (40项)  

**1. 身份与标识 (UA & Global)**  

global_seed: 全局确定性随机种子，确保同种子下指纹一致

ua_string: 自定义 navigator.userAgent

platform: 伪装 navigator.platform (例: Win32/MacIntel)

language: 伪装 navigator.language 及请求头

platform_version: 内部系统版本标识

mobile: 切换移动端/桌面端模拟模式

**2. 核心硬件 (Hardware)**  

concurrency: CPU 线程数（自动向上取偶）

device_memory: 内存容量（自动向下取 2 的幂次方）

**3. 图形与渲染 (WebGL & Canvas)**

webgl_vendor: 显卡供应商

webgl_renderer: 显卡渲染器型号

clear_color_noise: WebGL 颜色缓冲噪声

viewport_noise_max: 视口尺寸微调干扰

read_pixels_noise_max: 像素读取数据干扰

canvas_measure_text_noise: Canvas 文本测量干扰

canvas_fill_text_offset: Canvas 文本填充位置偏移

rects_noise_factor: GetClientRects 几何位置微调干扰

**4. 屏幕显示 (Screen)**

width / height: 屏幕总分辨率

Width / Height: 屏幕可用分辨率。

color_depth: 屏幕色彩深度（通常为 24/32）

devicePixelRatio: 像素缩放比 (DPR)

**5. 字体与插件 (Fonts & Plugins)**  

fonts_offset_noise: 字体度量、间距干扰

fonts_whitelist: 字体枚举白名单（只允许网站检测到列表内的字体）

plugins_description_noise: 插件描述字符串随机化干扰

**6. 地理与时间 (Geo & Timezone)**  

zone_id: 强制修改时区（代码逻辑： 同时修改 ICU 库、JS Date 及系统环境变量 TZ）

latitude / longitude: 地理位置坐标

accuracy: 位置精度半径

**7. 网络与通信 (Network & WebRTC)**  

prevent_ip_leak: 强制禁用 WebRTC 泄露真实局域网/公网 IP

webrtc_device_label_noise: 媒体设备（麦克风/摄像头）标签干扰

downlink: 下行带宽

rtt: 网络往返时间

effective_type: 网络制式 (4g, wifi 等)

save_data: 节流模式开关状态

**8. 音频指纹 (Audio)**  

audio_sample_rate_offset: 采样率频率偏移

audio_reduction_noise: 音频压缩器特征干扰

**9. 电池状态 (Battery)**  

charging: 充电状态

level: 当前电量百分比

charging_time: 充满所需时间

discharging_time: 耗尽所需时间

**10. 实验性控制 (Internal)**  

media_config: 媒体设备枚举可见性控制

speech_config: 语音合成接口特征控制

使用教程

文件放置：将 fingerprint.json 放置在浏览器主程序（chrome.exe）同级目录下。

配置编辑：使用文本编辑器修改 JSON 内的参数。

生效验证：重启浏览器后访问 browserleaks.com 或 creepjs 查看效果。

准备好 Chromium 编译环境。

将本仓库中的文件按路径覆盖到你的 src 目录下。

执行编译脚本：

`ninja -C out\Release chrome`
