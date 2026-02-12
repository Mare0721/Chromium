
float DynamicsCompressorNode::reduction() const {
  float reduction_val = GetDynamicsCompressorHandler().ReductionValue();
  // [Modified] Fingerprint Spoofing
  const auto* config = FingerprintConfig::GetInstance();
  if (config && config->audio.spoofing_enabled) {
    // Add noise to reduction
    // reduction is usually in dB (negative).
    // Let's add small noise.
    // Use GenerateNoise with some seed (e.g. reduction value itself + salt?)
    // config->audio.reduction_noise_factor might be needed or just use default.
    double noise = FingerprintConfig::GenerateNoise(
        reduction_val, 0.001);  // 0.001 dB variation
    return reduction_val + static_cast<float>(noise);
  }
  return reduction_val;
}
