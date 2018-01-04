Pod::Spec.new do |s|   
 s.name = 'NIMSDK'     
 s.version = '4.6.0'
 s.summary = 'Netease IM SDK'
 s.homepage = 'http://netease.im'
 s.license = { :'type' => 'Copyright', :'text' => ' Copyright 2017 Netease '}   
 s.authors = 'Netease IM Team'  
 s.source = { :http => 'http://yx-web.nosdn.127.net/package%2FNIM_iOS_SDK_v4.6.0.zip'}  
 s.platform = :ios, '7.0'  
 s.vendored_libraries  = '**/Libs/*.a' 
 s.vendored_frameworks = '**/NIMSDK.framework','**/NIMAVChat.framework'  
 s.frameworks = 'SystemConfiguration', 'AVFoundation', 'CoreTelephony', 'AudioToolbox', 'CoreMedia' , 'VideoToolbox'  
 s.libraries = 'sqlite3.0', 'z', 'c++'
 s.resources  = '**/Resources/NMCVideoFilter.bundle'

end   
