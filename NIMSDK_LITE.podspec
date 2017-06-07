Pod::Spec.new do |s|   
 s.name = 'NIMSDK_LITE'
 s.version = '3.8.1'   
 s.summary = 'Netease IM Lite SDK'
 s.homepage = 'http://netease.im'   
 s.license = { :'type' => 'Copyright', :'text' => ' Copyright 2017 Netease '}  
 s.authors = 'Netease IM Team'  
 s.source = { :git => 'https://github.com/netease-im/NIM_iOS_SDK.git', :tag => '3.8.1'}  
 s.platform = :ios, '7.0'
 s.vendored_libraries  = 'NIMSDK/Libs/*.a'
 s.vendored_frameworks = '**/NIMSDK.framework'  
 s.frameworks = 'SystemConfiguration', 'AVFoundation', 'CoreTelephony', 'AudioToolbox', 'CoreMedia' , 'VideoToolbox'   
 s.libraries = 'sqlite3.0', 'z', 'c++'  
end 
