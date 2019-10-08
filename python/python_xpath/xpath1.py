# 笔记
'''
使用//获取整个页面的元素，然后写标签名并用谓语提取
//div[@class='abc']

#注意1：一个/ 和 // 的区别？
'/'  代表的是获取直接子节点
'//' 获取子孙节点

# 注意2： 如果某个属性中包含了多个值，则使用contains
//div[contains(@class,'abc')]

# 注意3 谓语的下标是从0开始的
'''
from lxml import etree
text = '''
<table width="100%">
            <tr>
                <td class="f18 c5">请选择你要投出去的简历：</td>
            </tr>
            <tr>
                <td>
                    <form id="resumeSendForm" class="resumeSetForm">
                        <div class="resume-select-group">
                        <label class="radio">
                            <input type="radio" name="resumeName" class="resume1" value="1" data-resume-id="12522112"  checked  /> 在线简历：                             <span title="马泽的简历">马泽的简历</span>
                                                    </label>
                        <div class="setBtns">
                                                        <a href="https://www.lagou.com/resume/preview.html" target="_blank">预览</a>
                            |                             <a rel="nofollow" href="https://www.lagou.com/resume/myresume.html" target="_blank">修改</a>
                        </div>
                        <div class="resume-group">
                                                                                                                                                        </div>
                                                <div class="clear"></div>
                        <div class="upload-style">
                            <a target="_blank" title="上传附件简历" class="reUpload ">上传附件简历</a>
                            <input title="支持word、pdf、ppt、txt、wps格式文件，大小不超过10M" name="newResume" id="reUploadResume2" type="file" />
                        </div>
                                            </div>
                        <div class="clear"></div>
                        <span class="error" style="display:none;">只支持word、pdf、ppt、txt、wps格式文件，请重新上传</span>
                        <!-- <label class="tipsInfo">
                            <input type="checkbox" checked="checked" /> 默认使用此简历直接投递，下次不再提示
                        </label> -->
                        <div class="clear"></div>
                        <span class="setTip error"></span>
                        <input type="submit" class="btn_profile_save btn_s" value="确认投递简历" />
                    </form>
                </td>
            </tr>
        </table>
'''
# 使用HTML 类进行字符串的解析
def parse_text():
    htmlElement = etree.HTML(text)
    print(etree.tostring(htmlElement,encoding='utf-8').decode('utf-8'))

# 提取 html文件中的代码 进行解析
def parse_file():
    # 指定解析器
    parser = etree.HTMLParser(encoding="utf-8")
    htmlElement = etree.parse('F:/c_exercise/python/python_xpath/table.html',parser=parser)
    result = etree.tostring(htmlElement,encoding='utf-8')
    print(result.decode('utf-8'))
    
if __name__ == "__main__":
    parse_file()
    parse_text()