#include "retdec/demangler/borland_ast/function_node.h"

namespace retdec {
namespace demangler {
namespace borland {

/**
 * @brief Private function node constructor. Use create().
 * @param call_conv Pointer to calling convention.
 * @param name Pointer to Name or NestedName node.
 * @param params Pointer to parameters.
 */
FunctionNode::FunctionNode(
	std::shared_ptr<retdec::demangler::borland::Node> name,
	std::shared_ptr<FunctionTypeNode> funcType) :
	Node(Kind::KFunction, false),
	_name(std::move(name)),
	_funcNode(std::move(funcType)) {}

/**
 * @brief Creates shared pointer to function node.
 * @param call_conv Pointer to calling convention node.
 * @param name Pointer to Name or NestedName node.
 * @param params Pointer to parameters.
 * @return Unique pointer to constructed FunctionNode.
 */
std::shared_ptr<FunctionNode> FunctionNode::create(
	std::shared_ptr<retdec::demangler::borland::Node> name,
	std::shared_ptr<FunctionTypeNode> funcType)
{
	return std::shared_ptr<FunctionNode>(
		new FunctionNode(std::move(name), std::move(funcType)));
}

/**
 * @brief Prints text representation of function.
 * @param s Output stream.
 */
void FunctionNode::printLeft(std::ostream &s) const
{
	_funcNode->printLeft(s);
	_name->print(s);
	_funcNode->printRight(s);
}

}    // borland
}    // demangler
}    // retdec
