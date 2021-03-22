Pod::Spec.new do |s|

#名称
s.name         = 'ScreenAdapter'

#版本号
s.version      = '0.0.1'

#许可证
s.license      = { :type => 'MIT' } 

#项目主页地址 
s.homepage     = 'https://github.com/coder-zyy/ScreenAdapter'    

#作者
s.authors      = { 'coder-zyy' => 'coder_zyy@163.com' }

#简介
s.summary      = '屏幕适配工具'  

#项目的地址 （注意这里的tag位置，可以自己写也可以直接用s.version，但是与s.version一定要统一）
s.source       = { :git => 'https://github.com/coder-zyy/ScreenAdapter.git', :tag => s.version }

#需要包含的源文件 
s.source_files = 'ScreenAdapter/**/*.{h,m}'


#支持最小系统版本
s.platform     = :ios, '9.0'
s.requires_arc = true


#第三方依赖库
#s.dependency  'Moya'


#依赖库
s.frameworks   = 'UIKit','Foundation'

end
