require 'open-uri'
require 'json'

def abort(message)
    $stderr.puts("Error: #{message}\n\nAborting.")
    exit(1)
end

asset_name = ENV.fetch('ASSET_NAME') { abort 'ASSET_NAME env var must be provided.' }
asset_url = "https://github.com/lib-ruby-parser/bench/releases/download/v4.0.0+ruby-3.1.0/#{asset_name}"
save_as = ENV.fetch('SAVE_AS') { abort 'SAVE_AS env var must be provided' }

File.open(save_as, 'wb') do |file|
    URI.open(asset_url, 'rb') do |asset|
        file.write(asset.read)
    end
end
