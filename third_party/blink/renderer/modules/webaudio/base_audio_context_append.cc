
// [Added] Fingerprint Spoofing Implementation
float BaseAudioContext::sampleRate() const {
  float rate = destination_handler_->SampleRate();
  // [Modified] Fingerprint Spoofing
  // Use a local static or just check instance to avoid performance hit if
  // possible? But FingerprintConfig::GetInstance() is fast (static pointer).
  const auto* config = FingerprintConfig::GetInstance();
  if (config && config->audio.spoofing_enabled) {
    // If a specific offset is provided in config, use it.
    // Otherwise, generating noise might be better.
    // But for determinism, we need a seed.
    // We can use the global seed + rate as input.

    double noise = 0.0;
    if (config->audio.sample_rate_offset != 0.0) {
      // Use fixed offset if provided (e.g. for specific testing)
      noise = config->audio.sample_rate_offset;
    } else {
      // Generate deterministic noise
      // Input: rate (e.g. 44100 or 48000)
      // Factor: 100 (from legacy field) or just arbitrary small range?
      // Let's use legacy max offset field if available, or default.
      double max_offset =
          static_cast<double>(config->GetAudioSampleRateOffsetMax());
      if (max_offset <= 0) {
        max_offset = 100.0;
      }

      noise = FingerprintConfig::GenerateNoise(rate, max_offset);
    }
    return rate + static_cast<float>(noise);
  }
  return rate;
}
