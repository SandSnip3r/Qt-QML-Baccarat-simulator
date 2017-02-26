import QtQuick 2.6
import QtQuick.Controls 2.1
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1400
    height: 900
    title: qsTr("Baccarat Simulator")

    Row {
        anchors.fill: parent

        Column {
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: parent.width * .15

            Rectangle {
                width: parent.width
                height: parent.height
                color: "red"
                border.color: "black"
                border.width: 2
            }
        }

        Column {
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: parent.width * .7

            Rectangle {
                //Game panel
                width: parent.width
                height: parent.height * .8
                color: "green"
                border.color: "black"
                border.width: 2

                Rectangle {
                    //Card panel
                    width: parent.width*.95
                    anchors.horizontalCenter: parent.horizontalCenter
                    height: parent.height*.3
                    anchors.top: parent.top
                    anchors.topMargin: parent.height * 0.01
                    color: "transparent"
                    border.color: "black"
                    border.width: 1

                    property double cardImageHeight: height * .95
                    property double betweenCardMargin: 5

                    Image {
                        //P3
                        anchors.right: p2CardImage.left
                        anchors.rightMargin: parent.betweenCardMargin
                        anchors.verticalCenter: parent.verticalCenter
                        height: parent.cardImageHeight
                        fillMode: Image.PreserveAspectFit
//                        source: "Cards/AS.svg"
                        source: "Cards/"+simulator.p3CardString+".svg"
                    }

                    Image {
                        id: p2CardImage
                        anchors.right: p1CardImage.left
                        anchors.rightMargin: parent.betweenCardMargin
                        anchors.verticalCenter: parent.verticalCenter
                        height: parent.cardImageHeight
                        fillMode: Image.PreserveAspectFit
                        source: "Cards/"+simulator.p2CardString+".svg"
                    }

                    Image {
                        id: p1CardImage
                        anchors.right: verticalCardDividerBar.left
                        anchors.rightMargin: parent.betweenCardMargin
                        anchors.verticalCenter: parent.verticalCenter
                        height: parent.cardImageHeight
                        fillMode: Image.PreserveAspectFit
                        source: "Cards/"+simulator.p1CardString+".svg"
                    }

                    Rectangle {
                        id: verticalCardDividerBar
                        height: parent.height * .8
                        width: 3
                        color: "black"
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    Image {
                        id: b1CardImage
                        anchors.left: verticalCardDividerBar.right
                        anchors.leftMargin: parent.betweenCardMargin
                        anchors.verticalCenter: parent.verticalCenter
                        height: parent.cardImageHeight
                        fillMode: Image.PreserveAspectFit
                        source: "Cards/"+simulator.b1CardString+".svg"
                    }

                    Image {
                        id: b2CardImage
                        anchors.left: b1CardImage.right
                        anchors.leftMargin: parent.betweenCardMargin
                        anchors.verticalCenter: parent.verticalCenter
                        height: parent.cardImageHeight
                        fillMode: Image.PreserveAspectFit
                        source: "Cards/"+simulator.b2CardString+".svg"
                    }

                    Image {
                        //B3
                        anchors.left: b2CardImage.right
                        anchors.leftMargin: parent.betweenCardMargin
                        anchors.verticalCenter: parent.verticalCenter
                        height: parent.cardImageHeight
                        fillMode: Image.PreserveAspectFit
                        source: "Cards/"+simulator.b3CardString+".svg"
                    }
                }
            }

            Rectangle {
                //Button panel
                width: parent.width
                height: parent.height * .2
                color: "orange"
                border.color: "black"
                border.width: 2

                RoundButton {
                    id: playButton
                    anchors.left: parent.left
                    anchors.leftMargin: parent.width * .1
                    anchors.top: parent.top
                    anchors.topMargin: parent.height * .1
                    property double calculatedWidth: parent.width * 0.08
                    property double minWidth: 75
                    width: (calculatedWidth > minWidth) ? calculatedWidth : minWidth
                    height: parent.height * 0.15
                    text: simulator.running ? "Stop" : "Start"
                    radius: height * .1
                    onClicked: {
                        simulator.play()
                    }
                }

                Rectangle {
                    id: textBox
                    width: parent.width * .3
                    height: parent.height * .7
                    anchors.left: playButton.right
                    anchors.leftMargin: parent.width * .02
                    anchors.verticalCenter: parent.verticalCenter
                    border.color: "black"
                    border.width: 2
                    color: "#5500AA"
                    Column {
                        anchors.fill: parent
                        Text {
                            anchors.horizontalCenter: parent.horizontalCenter
                            height: textBox.height/2
                            width: parent.width
                            color: "white"
                            text: simulator.gamePlayedCount + (simulator.gamePlayedCount == 1 ? " game" : " games") + " played"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                        Text {
                            anchors.horizontalCenter: parent.horizontalCenter
                            height: textBox.height/2
                            width: parent.width
                            color: "white"
                            text: "Player score: " + simulator.playerScore + ", Banker score: " + simulator.bankerScore
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }
            }
        }

        Column {
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: parent.width * .15

            Rectangle {
                width: parent.width
                height: parent.height
                color: "olive"
                border.color: "black"
                border.width: 2
            }
        }
    }
}
