
float BaseAudioContext::sampleRate() const {
  float rate = destination_handler_->SampleRate();
  // [Modified] Fingerprint Spoofing
  const auto* config = FingerprintConfig::GetInstance();
  if (config && config->audio.spoofing_enabled) {
    // Use noise scale from config or default small offset
    // Assuming audio.sample_rate_offset exists or we use GenerateNoise
    // Let's use GenerateNoise with a fixed seed based on rate for determinism?
    // Or if config provides a specific offset.
    // Based on previous greps, GetAudioSampleRateOffsetMax existed.
    double offset = FingerprintConfig::GenerateNoise(
        rate, config->audio.sample_rate_offset);
    return rate + static_cast<float>(offset);
  }
  return rate;
}
