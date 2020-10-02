# frozen_string_literal: true

require 'rubygems'
require 'rubygems/package_task'

spec = Gem::Specification.new do |s|
  s.name = 'semacode'
  s.version = '0.7.5'
  s.author = 'Guido Sohne'
  s.email = 'guido@sohne.net'
  s.homepage = 'http://sohne.net/projects/semafox/'
  s.licenses = ["GPL-2.0".freeze]
  s.platform = Gem::Platform::RUBY
  s.summary = 'Create semacodes (2D barcodes) using Ruby.'
  s.description = <<DESC
  This Ruby extension implements a DataMatrix encoder for Ruby. It is typically
  used to create semacodes, which are barcodes, that contain URLs. This encoder
  does not create image files or visual representations of the semacode. This is
  because it can be used for more than creating images, such as rendering
  semacodes to HTML, SVG, PDF or even stored in a database or file for later
  use.
DESC

  s.extensions << 'ext/extconf.rb'
  s.add_dependency('rake', '~> 0.7', '>= 0.7.0')
  s.files = FileList[
    '{lib,ext}/**/*.rb',
    'ext/**/*.c',
    'ext/**/*.h',
    'tests/**/*.rb',
    'README.rdoc',
    'CHANGELOG',
    'Rakefile'].to_a
  s.require_path = 'lib'
  s.test_files = FileList['{tests}/**/*test.rb'].to_a
end

Gem::PackageTask.new(spec) do |pkg|
  pkg.need_zip = true
  pkg.need_tar_gz = true
  pkg.need_tar_bz2 = true
end

task default: "pkg/#{spec.name}-#{spec.version}.gem" do
  puts "Successfully created #{spec.name}-#{spec.version} gem"
end

if $PROGRAM_NAME == __FILE__
  Gem.manage_gems
  Gem::Builder.new(spec).build
end
