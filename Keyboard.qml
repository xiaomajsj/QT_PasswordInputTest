import QtQuick 2.10
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.VirtualKeyboard 2.2

Item {
    TextField {
        id:appcontainer
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        focus: true
        placeholderText: "Password"
        inputMethodHints: Qt.ImhDigitsOnly
        onPressed: {
            vkb.visible = true; //当选择输入框的时候才显示键盘
     }
 }
    InputPanel {
        id: vkb
        visible: false
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
                //这种集成方式下点击隐藏键盘的按钮是没有效果的，
                //只会改变active，因此我们自己处理一下
       onActiveChanged: {
            if(!active) { visible = false; }
         }

    }
}
