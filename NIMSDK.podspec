Pod::Spec.new do |s|   
 s.name = 'NIMSDK'     
 s.version = '6.9.0'
 s.summary = 'Netease IM SDK'
 s.homepage = 'http://netease.im'
 s.license = { :'type' => 'Copyright', :'text' => ' Copyright 2019 Netease '}   
 s.authors = 'Netease IM Team'  
 s.source = { :http => 'http://yx-web.nos.netease.com/package/1568717594/NIM_iOS_SDK_v6.9.0.zip'}  
 s.platform = :ios, '8.0'  
 s.vendored_frameworks = '**/NIMSDK.framework','**/NIMAVChat.framework','**/NMC.framework','**/NMCBasicModuleFramework.framework'
 s.frameworks = 'SystemConfiguration', 'AVFoundation', 'CoreTelephony', 'AudioToolbox', 'CoreMedia' , 'VideoToolbox'  , 'CoreLocation' 
 s.libraries = 'sqlite3.0', 'z', 'c++'
 s.resources  = '**/Resources/NMCVideoFilter.bundle'

end   
