<?php

/*
 * Extend the NodeBlock class to find the appropriate translation of a node,
 * if available.
 *
 * NOTE: This is a bit of a hack, the swapNid() method doesn't account for the
 * possibility that settings['nid'] may be used after the title and content
 * have been loaded and could subsequently give erroneous results.
 */

class TranslatedNodeBlock extends NodeBlock {
	protected $already_swapped = false;

	function getAdminTitle() {
		return t('Existing content (translated)');
	}

	function getTitle() {
		$this->swapNid();
		return parent::getTitle();
	}

	function getContent() {
		$this->swapNid();
		return parent::getContent();
	}

	function swapNid() {
		$this->settings['nid'] = $this->findTranslation($this->settings['nid']);
	}

	function findTranslation($nid) {
		global $language;

		if ($this->already_swapped)
			return $nid;

		$node = node_load($nid);

		if (empty($node->tnid) || empty($node->langcode))
			return $nid;

		$translations = translation_node_get_translations($node->tnid);

		foreach ($translations as $code => $translation) {
			if ($code == $language->langcode)
				return $translation->nid;
		}

		return $nid;
	}
}
