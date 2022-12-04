#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "chatbot.h"
#include "chatgui.h"
#include "chatlogic.h"
#include "graphedge.h"
#include "graphnode.h"


/********* ChatBotPanelDialog Tests **********/

class GetChatLogicHandleTestsFixture : public testing::Test {
    public:
        void SetUp() {
            chatBotFrame = new ChatBotFrame("Fake Frame");
            // create panel with background image
            ctrlPanel = new ChatBotFrameImagePanel(chatBotFrame);
            // create controls and assign them to control panel
            panelDialog = new ChatBotPanelDialog(ctrlPanel, wxID_ANY);
            chatLogic = panelDialog->GetChatLogicHandle();
        }
        ChatBotPanelDialog* panelDialog;
        ChatBotFrameImagePanel *ctrlPanel;
        ChatBotFrame* chatBotFrame;
        ChatLogic* chatLogic;
};

TEST_F(GetChatLogicHandleTestsFixture, ChatLogicCreationTest) {
    ASSERT_NE(nullptr, chatLogic); 
}

TEST_F(GetChatLogicHandleTestsFixture, ChatLogicTypeTest) {
    ASSERT_EQ(typeid(chatLogic), typeid(ChatLogic*)); 
}


/********* ChatLogic Tests **********/

class AddAllTokensToElementFixture : public testing::Test {
    public:
        void SetUp() {
            
            tokens_node = {std::pair<std::string, std::string>{"TYPE", "NODE"},
                          std::pair<std::string, std::string>{"ID", "0"},
                          std::pair<std::string, std::string>{"ANSWER", "THE ANSWER"}
                          };

            node = std::make_unique<GraphNode>(node_id);
            edge = std::make_unique<GraphEdge>(edge_id);

            token_edge = {std::pair<std::string, std::string>{"TYPE", "EDGE"},
                          std::pair<std::string, std::string>{"ID", "0"},
                          std::pair<std::string, std::string>{"PARENT", "0"},
                          std::pair<std::string, std::string>{"CHILD", "1"},
                          std::pair<std::string, std::string>{"KEYWORD", "pointer"},
                          std::pair<std::string, std::string>{"KEYWORD", "smart pointer"}
                         };
        }
    public:
        std::vector<std::pair<std::string, std::string>> tokens_node;
        std::vector<std::pair<std::string, std::string>> token_edge;
        int node_id{0};
        std::unique_ptr<GraphNode> node;
        std::unique_ptr<GraphEdge> edge;
        ChatLogic chatLogic;
        int edge_id{0};

};

TEST_F(AddAllTokensToElementFixture, AddAllTokensToElementNodeTest) {

    chatLogic.AddAllTokensToElement("ANSWER", tokens_node, *node);

    ASSERT_EQ("THE ANSWER", node->GetAnswers()[0]);
}

TEST_F(AddAllTokensToElementFixture, AddAllTokensToElementEdgeTest) {

    chatLogic.AddAllTokensToElement("KEYWORD", token_edge, *edge);

    ASSERT_EQ((std::vector<std::string>{"pointer", "smart pointer"}), edge->GetKeywords());
}


// TODO: Add LoadAnswerGraphFromFile tests
//       Add GraphEdge tests
//       Add GraphNode tests       
