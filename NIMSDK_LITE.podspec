Pod::Spec.new do |s|   
 s.name = 'NIMSDK_LITE'
 s.version = '4.7.3'   
 s.summary = 'Netease IM Lite SDK'
 s.homepage = 'http://netease.im'   
 s.license = { :'type' => 'Copyright', :'text' => ' Copyright 2017 Netease '}  
 s.authors = 'Netease IM Team'  
 s.source = { :http => 'http://yx-web.nosdn.127.net/package%2FNIM_iOS_SDK_IM_v4.7.3.zip'}  
 s.platform = :ios, '7.0'
 s.vendored_libraries  = 'NIMSDK/Libs/*.a'
 s.vendored_frameworks = '**/NIMSDK.framework'  
 s.frameworks = 'SystemConfiguration', 'AVFoundation', 'CoreTelephony', 'AudioToolbox', 'CoreMedia' , 'VideoToolbox'   
 s.libraries = 'sqlite3.0', 'z', 'c++'  
end 
