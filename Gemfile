source "https://rubygems.org"

# At least some of these are needed by Fastlane...
gem 'abbrev'
gem "mutex_m"
gem "csv"
gem "ostruct"
gem "nkf"
#  but I'm not sure which ones exactly...

gem 'cocoapods'
gem 'fastlane', '>= 2.228.0'

plugins_path = File.join(File.dirname(__FILE__), 'fastlane', 'Pluginfile')
eval_gemfile(plugins_path) if File.exist?(plugins_path)
