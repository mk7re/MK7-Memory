#pragma once

#include "../types.hpp"

#include <prim/seadSafeString.hpp>

/**
 * NOTE: All "name_offset"s are offsets relative to the start of the BSEQ's 
 * nametable, unless stated otherwise.
 */

BEGIN_NAMESPACE(Sequence)
{
    enum SectionType {
        SECTION_TYPE_PAGE,
        SECTION_TYPE_TASK,
        SECTION_TYPE_DATA_HOLDER,
        SECTION_TYPE_SERIAL_SEQUENCE,
        SECTION_TYPE_CROSS_FADE_SEQUENCE,
        SECTION_TYPE_PARALLEL_SEQUENCE,
        SECTION_TYPE_DELEGATE_SEQUENCE,
        SECTION_TYPE_SCENE_SEQUENCE_PROXY,
        SECTION_TYPE_ROOT   // root block of Root-Default.brs; the game ignores it and makes the root a ParallelSequence
    };

    enum SectionBlockType {
        SECTION_BLOCK_PRACTICAL_SECTION_TASK,   // Type: PracticalSectionBlock
        SECTION_BLOCK_PRACTICAL_SECTION_PAGE,   // Type: PracticalSectionBlock
        SECTION_BLOCK_SEQUENCE,                 // Type: SequenceBlock
        SECTION_BLOCK_CROSS_FADE_SEQUENCE,      // Type: CrossFadeSequenceBlock
        SECTION_BLOCK_SCENE_SEQUENCE_PROXY      // Type: SceneSequenceProxyBlock
    };

    // One entry of the engine creator table
    /START_CLASS/NAME@BSEQEngineCreatorTable/SIZE@0x4/
    public:
        /M/u16 m_engine_creator_name_offset/0x2/0x00/ // string: class name of the engine creator
        /M/u16 m_mode_name_offset/0x2/0x02/ // string: mode the engines are created for ("Menu", "Race", ...)
    /END/

    // *.brs / *.bss files
    /START_CLASS/NAME@BSEQ/SIZE@0x38/
    public:
        /M/u32 m_magic/0x4/0x00/        // BSEQ
        /M/u32 m_sequence_id/0x4/0x04/ // section ID of the file's root section
        /**
         * Num data
         */
        /M/u16 m_root_mode_id/0x2/0x08/ // mode ID of the file's root section
        /M/u16 field_0x0A/0x2/0x0A/ // always 4 in the game's files
        /M/u16 field_0x0C/0x2/0x0C/ // always 1 in the game's files
        /M/u16 m_num_sections/0x2/0xE/ // sum of the five pool sizes and of all m_num_instances; not bounds-checked
        /M/u16 m_num_serial_sequences/0x2/0x10/ // pool size: must cover the most SerialSequences active at once
        /M/u16 m_num_cross_fade_sequences/0x2/0x12/ // pool size: must cover the most CrossFadeSequences active at once
        /M/u16 m_num_parallel_sequences/0x2/0x14/ // pool size: must cover the most ParallelSequences active at once, root included
        /M/u16 m_num_delegate_sequences/0x2/0x16/ // pool size: must cover the most DelegateSequences active at once
        /M/u16 m_num_scene_sequence_proxy/0x2/0x18/ // pool size: must cover the most SceneSequenceProxies active at once
        /M/u16 m_num_layers/0x2/0x1A/ // layers of every ParallelSequence; at least the subsections of the largest parallel block
        /M/u16 m_num_section_block/0x2/0x1C/
        /M/u16 m_num_engine_creator/0x2/0x1E/
        /**
         * Offset data
         */
        /M/u32 field_0x20/0x4/0x20/ // always 0 in the game's files
        /M/u32 field_0x24/0x4/0x24/ // always 0 in the game's files
        /M/u32 m_first_section_block_offset/0x4/0x28/ // first section block, right after m_section_block_offsets
        // Type: BSEQEngineCreatorTable
        /M/u32 m_engine_creator_table_offset/0x4/0x2C/
        /M/u32 m_nametable_offset/0x4/0x30/ // string table, at the end of the file
        /M/u32 m_section_block_offsets[1]/0x4/0x34/ // m_num_section_block offsets of SectionBlocks, from the start of the file
    /END/

    /START_CLASS/NAME@SequenceResource/SIZE@0x14/
    public:
        // Forward declarations
        class SequenceBlock;
        class NameTableBlock;
        class PracticalSectionBlock;
        class CrossFadeSequenceBlock;
        class SceneSequenceProxyBlock;

        /START_CLASS/NAME@NameTableBlockEntry/SIZE@0x4/
        public:
            /M/u16 m_id/0x2/0x00/ // code value; unique only within its table
            /M/u16 m_name_offset/0x2/0x02/
        /END/

        /START_CLASS/NAME@StringTableBlock/SIZE@0x4/
        public:
            char *getString(u16) const;

            /M/char *m_strings/0x4/0x00/
        /END/

        // Right after this block ends, an array of `NameTableBlockEntry`.
        /START_CLASS/NAME@NameTableBlock/SIZE@0x4/
        public:
            const NameTableBlockEntry &searchItem(const sead::SafeString &, const StringTableBlock *) const;
            const NameTableBlockEntry &searchItem(u16) const;
            const NameTableBlockEntry &getItem(s32) const;

            /M/u16 m_num_entries/0x2/0x00/
            /M/u16 m_default_id/0x2/0x02/ // m_id used when a name is not found in the table
        /END/

        // Header of the section block. The size and exact contents of the whole SectionBlock can vary.
        /START_CLASS/NAME@SectionBlock/SIZE@0x14/
        public:
            const SequenceBlock &getSequence() const;
            const NameTableBlock &getEnterCodeTable() const;
            const NameTableBlock &getReturnCodeTable() const;
            const PracticalSectionBlock &getPracticalSection() const;
            const CrossFadeSequenceBlock &getCrossFadeSequence() const;
            const SceneSequenceProxyBlock &getSceneSequenceProxy() const;

            // See the `SectionType` enum
            /M/u8 m_section_type/0x1/0x00/
            /M/u16 field_0x02/0x2/0x02/
            /M/u32 m_sequence_id/0x4/0x04/ // section ID; a sequence has one block per mode, all with the same ID
            // Offset to the name of this block in the name table.
            /M/u16 m_section_block_name_offset/0x2/0x08/
            // Type: NameTableBlock
            /M/u16 m_enter_code_table_offset/0x2/0x0A/
            // Type: NameTableBlock
            /M/u16 m_return_code_table_offset/0x2/0x0C/
            // See the `SectionBlockType` enum
            /M/u16 m_block_type/0x2/0x0E/
            /M/u16 m_block_offset/0x2/0x10/ // type-specific block (see m_block_type), from the start of this SectionBlock
        /END/

        /**
         * Section Blocks
         */

        /START_CLASS/NAME@SubsectionListBlockEntry/SIZE@0x8/
        public:
            /M/u32 m_sequence_id/0x4/0x00/ // section ID of the child
            /M/u16 m_mode_id/0x2/0x04/ // mode ID the child is started in
        /END/

        // Right after this ends, an array of `SubsectionListBlockEntry` entries starts.
        /START_CLASS/NAME@SubsectionListBlock/SIZE@0x4/
        public:
            const SubsectionListBlockEntry &getItem(s32) const;

            /M/u16 m_num_entries/0x2/0x00/
        /END/

        // Right after this ends, an array of `SequenceBlockFlowListEntry` (or `CrossFadeSequenceBlockFlowListEntry`) entries starts.
        /START_CLASS/NAME@SequenceBlockFlowList/SIZE@0x4/
        public:
            /M/u16 m_num_entries/0x2/0x00/
        /END/

        // One transition: when the source ends with m_src_code, the destination starts with m_dst_code
        /START_CLASS/NAME@SequenceBlockFlowListEntry/SIZE@0x8/
        public:
            /M/s16 m_src_subsection_index/0x2/0x00/ // index into the subsection list; -1: the sequence itself
            /M/u16 m_src_code/0x2/0x02/ // return code ID of the source child; for -1, enter code ID of the sequence
            /M/s16 m_dst_subsection_index/0x2/0x04/ // index into the subsection list; -1: the sequence itself
            /M/u16 m_dst_code/0x2/0x06/ // enter code ID of the destination child; for -1, return code ID of the sequence
        /END/

        /START_CLASS/NAME@CrossFadeSequenceBlockFlowListEntry/SIZE@0xC/BASE@SequenceBlockFlowListEntry/BSIZE@0x8/
        public:
            /M/u16 m_cross_fade_type/0x2/0x08/ // low byte: a CrossFadeSequence::ECrossFadeType; high byte unused
        /END/
        
        /START_CLASS/NAME@PracticalSectionBlock/SIZE@0x8/
        public:
            const NameTableBlock &getModeTable() const;

            /M/u16 m_num_instances/0x2/0x00/ // objects created for this section; 1 in the game's files
            /M/u16 m_class_name_offset/0x2/0x02/ // string: C++ class name; an unknown name gets the Dummy class of the section type
            // Offset within this block where you will find the modeTable
            // Type: NameTableBlock
            /M/u16 m_mode_table_offset/0x2/0x04/
        /END/

        /START_CLASS/NAME@SequenceBlock/SIZE@0x8/
        public:
            const SequenceBlockFlowList &getFlowList() const;
            const SubsectionListBlock &getSubsectionList() const;

            /M/u16 m_mode_id/0x2/0x00/ // the mode this block implements (Section::m_mode_id)
            /M/u16 m_mode_name_offset/0x2/0x02/ // string: mode name; for a file's root, the second part of the file name
            // Offset within this block to the subsection list
            // Type: SubsectionList
            /M/u16 m_subsection_list_offset/0x2/0x04/
            // Offset within this block to the flow list
            // Type: SequenceBlockFlowList
            /M/u16 m_flow_list_offset/0x2/0x06/
        /END/

        /START_CLASS/NAME@CrossFadeSequenceBlock/SIZE@0x8/
        public:
            const SequenceBlockFlowList &getCrossFadeFlowList() const;

            /M/u16 m_mode_id/0x2/0x00/ // as in SequenceBlock
            /M/u16 m_mode_name_offset/0x2/0x02/ // as in SequenceBlock
            // Offset within this block to the subsection list
            // Type: SubsectionList
            /M/u16 m_subsection_list_offset/0x2/0x04/
            // Offset within this block to the flow list
            // Type: CrossFadeSequenceBlockFlowList
            /M/u16 m_flow_list_offset/0x2/0x06/
        /END/

        /START_CLASS/NAME@SceneSequenceProxyBlock/SIZE@0x8/
        public:
            /M/u16 m_mode_id/0x2/0x00/ // as in SequenceBlock
            /M/u16 m_mode_name_offset/0x2/0x02/ // string: mode name, the second part of the .bss name ("Default")
            /M/u16 m_scene_name_offset/0x2/0x04/ // string: scene to switch to ("Menu", "Race", ...); unknown names give Boot
        /END/

        void create(const sead::SafeString &, const sead::SafeString &, bool);
        s32 searchSectionType(u32) const;
        const SequenceBlock &searchSequenceBlock(u32, u16) const;
        const PracticalSectionBlock &searchPracticalSectionBlock(u32) const; 
        SequenceResource();
        ~SequenceResource();

        /M/BSEQ *m_bseq_file_buffer/0x4/0x00/
        /M/BSEQ *m_bseq/0x4/0x04/
        /M/char *m_string_table/0x4/0x08/ // the file's string table
        /M/BSEQEngineCreatorTable *m_engine_creator_table/0x4/0x0C/
        /M/SectionBlock **m_section_blocks/0x4/0x10/
    /END/
}