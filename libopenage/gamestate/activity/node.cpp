// Copyright 2023-2023 the openage authors. See copying.md for legal info.

#include "node.h"


namespace openage::gamestate::activity {

Node::Node(node_id id,
           node_label label,
           const std::vector<std::shared_ptr<Node>> &outputs) :
	outputs{},
	id{id},
	label{label} {
	this->outputs.reserve(outputs.size());
	for (const auto &output : outputs) {
		this->outputs.emplace(output->get_id(), output);
	}
}

node_id Node::get_id() const {
	return this->id;
}

const node_label Node::get_label() const {
	return this->label;
}

std::string Node::str() const {
	std::stringstream ret;
	if (this->label.empty()) {
		ret << this->get_id();
	}
	else {
		ret << this->get_label()
			<< " (id=" << this->get_id() << ")";
	}
	return ret.str();
}

} // namespace openage::gamestate::activity
