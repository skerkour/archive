#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#
Pod::Spec.new do |s|
  s.name             = 'flutter_secure_store'
  s.version          = '0.1.0'
  s.summary          = 'A simple and secure persistent key-value store for flutter. Values are stored encrypted.
  s.description      = <<-DESC
A new flutter plugin project.
                       DESC
  s.homepage         = 'https://gitlab.com/bloom42/libs/flutter_secure_store'
  s.license          = { :file => '../LICENSE.txt' }
  s.author           = { 'Bloom' => 'hello@bloom.sh }
  s.source           = { :path => '.' }
  s.source_files = 'Classes/**/*'
  s.public_header_files = 'Classes/**/*.h'
  s.dependency 'Flutter'

  s.ios.deployment_target = '8.0'
end

